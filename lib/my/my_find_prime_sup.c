/*
** EPITECH PROJECT, 2019
** my_find_prime_sup
** File description:
** find superior prime number
*/

void my_putchar(char c);

int static check_if_prime(int number)
{
    int prime_checker = 3;

    if (number % 2 == 0) {
        return (0);
    }
    while (prime_checker <= 9) {
        if (number % prime_checker == 0) {
            return (0);
        } else {
            return (1);
            }
        prime_checker += 2;
    }
}

int my_find_prime_sup(int nb)
{
    int prime_found = nb;
    int temp = 0;

    if ( nb <= 1 || nb == 0 || nb == 2) {
        return (2);
    }
    temp = check_if_prime(prime_found);
    while (temp == 0) {
        prime_found++;
        temp =  check_if_prime(prime_found);
    }
    return (prime_found);
}
