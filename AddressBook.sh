#1/bin/sh

echo "" > emp.txt

while true;

do

        echo -e "1.Insert record \n2.Display record \n3.Search record \n4.Delete record \n5.Modify record"

        echo -e "\nEnter your choice:"

        read ch

        v=1

        case $ch in

                 1)

                            while [ $v -eq 1 ]

                            do

                                  echo -e "Enter eno :"

                                  read eno

                                  echo -e "Enter ename :"

                                  read ename

                                  echo -e "Enter mobile number :"

                                  read mobno

                                  echo -e "Enter city :"

                                  read city

                                  echo -e "$eno \t $ename \t $mobno \t $city">>emp.txt

                                  echo -e "\nDo you want to continue? Press 1 to continue or 0 to exit"

                                  read v

                                  

                            done

                 ;;

                 

                 2)

                            cat emp.txt

                 ;;

                 

                 3)

                            echo -e "\nEnter the employee name:"

                            read ename

                            grep $ename emp.txt

                 ;;

                 

                 4)

                            echo -e "\nEnter employee name to delete:"

                            read ename

                            grep -v $ename emp.txt >> temp.txt

                            rm emp.txt

                            mv temp.txt emp.txt

                 ;;

                 

                 5)

                            echo -e "\nEnter employee name to modify:"

                            read ename

                            echo -e "\nEnter the new employee name:"

                            read name

                            sed -i s/$ename/$name/g emp.txt

                 ;;

                 

                 6)

                            exit

                 ;;

                 

                 *)

        esac

done

