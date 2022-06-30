clear
tput setaf 2; echo "HACKING THE MAINFRAME: "
echo
echo -n "["
i=10
while [ $i -ge 0 ]
do
        sleep 1s
        tput setaf 2; echo -n ".."
        ((i--))
done
echo ".]"
echo
echo
echo "MAINFRAME HAS BEEN HACKED"
echo
echo "PROGRAMM WILL CLOSE IN 5 sec"
sleep 5s
clear
exit