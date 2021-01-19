#include <pthread.h>
#include <unistd.h>
#include <cstdio>
using namespace std;

pthread_t p[5];
pthread_mutex_t forks[5];

void *eat(void *nr)
{
    int x = *((int *)(&nr));
    int number = (x + 1);
    printf("Philosopher %d is thinking -HMM-\n", number);

    pthread_mutex_lock(&forks[x]);
    pthread_mutex_lock(&forks[(x + 1) % 5]);

    if (number == 5)
    {
        printf("+]Philosopher %d took a fork nr %d\n", number, number);
        printf("+]Philosopher %d took a fork nr %d\n", number, 1);
    }
    else
    {
        printf("+]Philosopher %d took a fork nr %d\n", number, number);
        printf("+]Philosopher %d took a fork nr %d\n", number, (number + 1) % 6);
    }

    printf("Philosopher %d is eating :)\n", number);
    sleep(2);

    pthread_mutex_unlock(&forks[x]);
    pthread_mutex_unlock(&forks[(x + 1) % 5]);

    if (number == 5)
    {
        printf("-]Philosopher %d unlock fork nr %d\n", number, number);
        printf("-]Philosopher %d unlock fork nr %d\n", number, 1);
    }
    else
    {
        printf("-]Philosopher %d unlock fork nr %d\n", number, number);
        printf("-]Philosopher %d unlock fork nr %d\n", number, (number + 1) % 6);
    }

    return nullptr;
}

int main()
{
    for (int i = 0; i < 5; i++)
        pthread_mutex_init(&forks[i], nullptr);

    for (int j = 0; j < 5; j++)
        pthread_create(&p[j], nullptr, eat, (void *)j);

    for (int k = 0; k < 5; k++)
        pthread_join(p[k], nullptr);

    return 0;
}