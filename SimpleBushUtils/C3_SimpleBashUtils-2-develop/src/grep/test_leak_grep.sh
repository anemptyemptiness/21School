#!/bin/bash

SUCCESS=0
FAIL=0
COUNTER=0
RESULT=0
DIFF_RES=""

declare -a tests=(
"VAR int test_0_grep.txt"
"VAR size test_1_grep.txt"
"VAR for test_2_grep.txt"
)


testing()
{
    t=$(echo $@ | sed "s/VAR/$var/")
    leaks -quiet -atExit -- ./s21_grep $t > test_s21_grep.log
    leak=$(grep -A100000 leaks test_s21_grep.log)
    (( COUNTER++ ))
    if [[ $leak == *"0 leaks for 0 total leaked bytes"* ]]
    then
      (( SUCCESS++ ))
        echo "\033[31m$FAIL\033[0m/\033[32m$SUCCESS\033[0m/$COUNTER \033[32msuccess\033[0m grep $t"
    else
      (( FAIL++ ))
        echo "\033[31m$FAIL\033[0m/\033[32m$SUCCESS\033[0m/$COUNTER \033[31mfail\033[0m grep $t"
#        echo "$leak"
    fi
    rm test_s21_grep.log
}


# 1 параметр
for var1 in v c l n h e i 
do
    for i in "${tests[@]}"
    do
        var="-$var1"
        testing $i
    done
done



echo "\033[31mFAIL: $FAIL\033[0m"
echo "\033[32mSUCCESS: $SUCCESS\033[0m"
echo "ALL: $COUNTER"
