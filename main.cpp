#include <iostream>
#include <unistd.h>
#include <sys/types.h>

// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main() {

    int pipefd[2];

    if (pipe(pipefd) == -1) {perror("pipe error"); return 1;}

    int RandomNumArray[20];

    int randomNum = 0;

    std::srand(std::time(0));

    for (int i = 0; i <= 19; i++) {
        randomNum = (std::rand()% 100) + 1;
        RandomNumArray[i] = randomNum;
         // std::cout << RandomNumArray[i] << std::endl;
    }

        int temp = 100;
        int ParentMin = 0;
        int ChildMin = 0;

     pid_t pid = fork();

       if (pid > 0) {
           // parent process finds first half min num
           for (int i = 0; i <= 9; i++) {

               if (RandomNumArray[i] < temp) {
                   temp = RandomNumArray[i];
               }

               if (i == 9) {
                   ParentMin = temp;
                   std::cout<< "Parent PID = " << getpid() << std::endl;
                   std::cout << "Parent Min Num = " << ParentMin << std::endl;

               }

           }
       }
            // Child Process for second half min nums
           if (pid == 0) {
               temp = 100;
               for (int i = 10; i <= 19; i++) {

                   if  (RandomNumArray[i] < temp) {
                      temp = RandomNumArray[i];
                   }

                   if (i == 19) {
                       ChildMin = temp;
                       write(pipefd[1],&ChildMin, ChildMin);
                       std::cout<<"Child PID = " << getpid() << std::endl;
                       std::cout << "Child Min Num = " << ChildMin << std::endl;
                       close(pipefd[1]);
                   }

               }

               int ParentReceivedChild;

               if (read(pipefd[0],&ParentReceivedChild,sizeof(ParentReceivedChild)) > 0) {
                   std::cout << "Parent received Child Num = " << ParentReceivedChild << std::endl;
               }

               else{std::cout<<"Error"<<std::endl;}
           }

    return 0;
}

// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.