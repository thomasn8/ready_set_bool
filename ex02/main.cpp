#include "utils.hpp"

bool g_mirror_details = false;
bool g_calculation_details = false;
bool g_final_values = false;

size_t getNumberOfMirrorings(size_t n)
{
	if (n <= 1)
		return 0;

	size_t e = 0;
	while (n >= myPow(2, e))
		e++;
	return e - 1;
}

// Calcule l'index du nombre correspondant par symétrie dans le précédant block de nombre
size_t getIndexMirroredNumber(size_t n, size_t e)
{
	return myPow(2, e + 1) - n - 1;
}

// Calcule la valeur constante à ajouter à chacune des valeurs du block pour obtenir la valeur miroir + grande et unique
size_t constantAddForBlock(size_t e)
{
	return myPow(2, e);
}

size_t gray_code(size_t n)
{
	size_t mirrorings = getNumberOfMirrorings(n); // donne le nombre de réflexions de bloc de bits à faire (miroirs)
	if (g_calculation_details)
	{
		std::cout << "Nombre à convertir: " << n << std::endl;
		std::cout << "Nombre de symétries à faire: " << mirrorings << std::endl;
	}

	// Créer le block inital à 2 valeurs
	size_t *block = (size_t *)malloc(2 * sizeof(size_t));
	block[0] = 0;
	block[1] = 1;

	for (size_t e = 0; e < mirrorings; e++)
	{
		size_t currentBlockLength = myPow(2, e + 1);
		size_t nextBlockLength = myPow(2, e + 2);
		size_t *tmp = (size_t *)malloc(nextBlockLength * sizeof(size_t));

		for (size_t i = 0; i < currentBlockLength; i++)
			tmp[i] = block[i];
		free(block);
		block = tmp;

		// Calculer + mémoriser les nouvelles valeurs en utilisant les valeurs symétriques du block précédant:
		// newValue = symetricalValue + constantAddForBlock
		for (size_t n = currentBlockLength; n < nextBlockLength; n++)
		{
			size_t indexMirroredNumber = getIndexMirroredNumber(n, e + 1);
			size_t newValue = block[indexMirroredNumber] + constantAddForBlock(e + 1);
			block[n] = newValue;

			if (g_calculation_details)
				printSymmetricalAdditionDetails(e, n, indexMirroredNumber, block);
		}
		if (g_mirror_details)
			printBlockMirror(block, nextBlockLength);
	}

	if (g_final_values)
		printBlockValues(block, myPow(2, mirrorings + 1));
	int convertedValue = block[n];
	free(block);
	return convertedValue;
}

int main()
{
	std::cout << gray_code(0) << std::endl;
	std::cout << gray_code(1) << std::endl;
	std::cout << gray_code(2) << std::endl;
	std::cout << gray_code(3) << std::endl;
	std::cout << gray_code(4) << std::endl;
	std::cout << gray_code(5) << std::endl;
	std::cout << gray_code(6) << std::endl;
	std::cout << gray_code(7) << std::endl;
	std::cout << gray_code(8) << std::endl;
	return 0;
}