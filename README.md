*This project has been created as part of the 42 curriculum by mcrenn.*

#  Philosophers

## 🤔 Description:
First, the principle of philosophers: \
We have a round table with a number N of philosophers and a big plate of spaghetti in its center. Each philosopher had **a unic** fork, but to eat correctly, they have to use two forks. \
So while some philosophers eat the spaghetti with their own forks and the forks of his mates, the philosophers whithout forks have to think until they have two forks to eat. \
If they did'nt eat and they pass a certain time, they die. After eating, a philosopher sleep for a certain amount of time and think while they did'nt have two forks.

The goal of this project is project is to print the state of every philosopher in the terminal. Those states are:
- Philo has taken a fork
- Philo is eating (Informating that the philo strat eating).
- Philo is sleeping (The philo has finish to eat, now sleeping for an amount of time).
- Philo is thinking (The philo is waiting a fork).
- Philo died (trigger end of progam because a philosoher died).


## 📏 Instructions:
To use this project, you must clone my [repository](https://github.com/ManoPotame/42-Philosophers):
```bash
git clone https://github.com/ManoPotame/42-Philosophers.git
```
Once the repo cloned, you can go to the folder, next go to the 'philo' directory to finally type the `make` command.
```bash
# The content of Philosopher is in the philo directory
cd philo

# Now you can make and it will be create a executable called `philo`
make
```
Now, you can execute the program by using the executable `philo`. Note for this project, you cannot execute the project without a minimum of 4 arguments:
- The number of philosophers (av[1])
- The time to die in ms (av[2])
- The time to eat in ms (av[3])
- The time to sleep in ms (av[4])

And as optional argument, you can use the number of times philosophers must eat av[5], wich this will stop the program when all philosophers are eats all the spaghettis they wan't to eat !
Note that the program support a maximum of 200 philosophers.
```bash
# Here the program lauch:
# For 5 philosophers,
# They will die if, after 800ms, a philosophers did'nt eat anymore,
# Each of them takes 200ms to eat,
# They take a nap while 200ms,
# (optionaly) Each philosopher have to eat 7 times.
./philo 5 800 200 200 7
```

## 📚 Ressources:
- Understanding the [thread](https://en.wikipedia.org/wiki/Thread_(computing)) and [multithreading](https://en.wikipedia.org/wiki/Multithreading_(computer_architecture)) system.
- The [guide](https://medium.com/@ruinadd/philosophers-42-guide-the-dining-philosophers-problem-893a24bc0fe2) I followed to do this project.
