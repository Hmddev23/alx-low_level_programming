int add(int i, int k);
int sub(int i, int k);
int mul(int i, int k);
int div(int i, int k);
int mod(int i, int k);

/**
  * add - Add two integers.
  *
  * @i: Integer parameter.
  * @k: Integer parameter.
  *
  * Return: Result of the sum.
  */

int add(int i, int k)
{
	return (i + k);
}

/**
  * sub - Subtract two integers.
  *
  * @i: Integer parameter.
  * @k: Integer parameter.
  *
  * Return: Result of the subtractration.
  */

int sub(int i, int k)
{
	return (i - k);
}

/**
  * mul - Multiply two integers.
  *
  * @i: Integer parameter.
  * @k: Integer parameter.
  *
  * Return: Result of the multiplication.
  */

int mul(int i, int k)
{
	return (i * k);
}

/**
  * div - Divid two integers.
  *
  * @i: Integer parameter.
  * @k: Integer parameter.
  *
  * Return: the dividend integer.
  */

int div(int i, int k)
{
	return (i / k);
}

/**
  * mod - Find the modulo of two integers.
  *
  * @i: Integer parameter.
  * @k: Integer parameter.
  *
  * Return: Result of the modulo
  */

int mod(int i, int k)
{
	return (i % k);
}
