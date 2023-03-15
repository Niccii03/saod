void Swap(int& x, int& y)
{
	int* px = &x, * py = &y;
	int t = *px;
	*px = *py;
	*py = t;
}