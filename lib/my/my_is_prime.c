/*
** EPITECH PROJECT, 2019
** my_is_prime
** File description:
** checks if prime or not
*/

void my_putchar(char c);

int static find_prime(int number)
{
    int prime_checker = 3;

    while (prime_checker <= 9) {
        if (number % prime_checker == 0) {
            return (0);
        } else {
            return (1);
        }
        prime_checker += 2;
    }
}

int my_is_prime(int nb)
{
    if ( nb == 1 || nb == 0) {
        return (0);
    }
    if ( nb % 2 == 0) {
        return (0);
    }
    nb = find_prime(nb);
    return (nb);
}
