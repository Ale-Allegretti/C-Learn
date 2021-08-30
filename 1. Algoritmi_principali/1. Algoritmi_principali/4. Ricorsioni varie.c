
/*media ricorsiva*/double mediaRic(int sommaParziale, int n) {
	int num;
	printf("inserisci nuovo numero (zero per terminare): ");
	scanf_s("%d", &num);
	if (num == 0)
		return ((double)sommaParziale) / n;
	else
		return mediaRic(sommaParziale + num, n + 1);
}

