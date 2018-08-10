Passing by Reference

int refVar(int &);

int main()
{
    int value = 20;
    refVar(value);
}

int refVar(int &refVar)
{
    return refVar + 5;
}