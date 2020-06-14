void quick_sort(int long *vetor, int long esquerda, int long direita)
{
  int long i, j, x, y;

  i = esquerda;
  j = direita;
  x = vetor[(esquerda + direita) / 2];

  while (i <= j)
  {
    while (vetor[i] < x && i < direita)
    {
      i++;
    }
    while (vetor[j] > x && j > esquerda)
    {
      j--;
    }
    if (i <= j)
    {
      y = vetor[i];
      vetor[i] = vetor[j];
      vetor[j] = y;
      i++;
      j--;
    }
  }

  if (j > esquerda)
  {
    quick_sort(vetor, esquerda, j);
  }
  if (i < direita)
  {
    quick_sort(vetor, i, direita);
  }
}