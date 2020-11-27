/*
** EPITECH PROJECT, 2020
** t5d4
** File description:
** t5d4
*/

struct var
{
    int i;
    int x;
    int nb;
    int nbt;
    int n;
};

int my_getnbr(char const *str)
{
    struct var v = {0};
    for (; str[v.i] != '\0'; v.i++) {
        if (str[v.i] == 45) {
            v.x++;
        }
        if (str[v.i] >= 48 && str[v.i] <= 57) {
            for (; str[v.i] >= 48 && str[v.i] <= 57; v.i++) {
                v.nb = str[v.i] - 48;
                v.nbt = v.nbt * 10 + v.nb;
                v.n++;
            }
        }
    }
    if (v.x % 2 == 1)
        v.nbt = v.nbt * (-1);
    if (v.n > 10)
        return (0);
    return (v.nbt);
}