

/*ORDINE ALFABETICO */ int main() 
{
	char c1, c2, c3;
	char first, second, third;
	char temp1, temp2;

	scanf_s("%c%c%c", &c1, 1, &c2, 1, &c3, 1);

	first = ((c1 < c2) ? (temp1 = c2, c1) : (temp1 = c1, c2));
		/*Se VERO c1<c2 , allora first=c2 e temp1 = c1;   Se FALSO, allora first=c1 e temp1 = c2*/

	first = ((first < c3) ? (temp2 = c3, first) : (temp2 = first, c3));
	second = ((temp1 < temp2) ? (third = temp2, temp1) : (third = temp1, temp2));
	printf("Characters: %c %c %c\n", first, second, third);
	return 0;
}