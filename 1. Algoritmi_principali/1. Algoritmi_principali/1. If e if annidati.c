
/* VOTI OLIMPIADI */ int main() 
{
	float v1, v2, v3, v4;
	float maxV = 0.0F /*necessario impostare un valore iniziale*/;
	float media;

	printf("Inserire quattro voti: "); scanf_s("%f %f %f %f", &v1, &v2, &v3, &v4);

	if (
			(v1 >= 0.0 && v1 <= 10.0) &&
			(v2 >= 0.0 && v2 <= 10.0) &&
			(v3 >= 0.0 && v3 <= 10.0) &&
			(v4 >= 0.0 && v4 <= 10.0)
		) {
			maxV = v1;
			if (v2 > maxV) maxV = v2;
			if (v3 > maxV) maxV = v3;
			if (v4 > maxV) maxV = v4;
			media = (v1 + v2 + v3 + v4 - maxV) / 3;
			printf("Voto medio: %f\n", media);
	}
	else 
			printf("Un voto inserito e' errato.\n");
return 0;
}