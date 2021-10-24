import cs50
import math



def main():
    
    
    #prompt user to input float value
    #I'm tryin to emnulate do-while loop in python. 
    #If user input positive, program while loop will stop, and store the date into dollors variable.
    while True:
        dollors = cs50.get_float("Change owed: ")
        if dollors >= 0:
            break
    
    #convert dollor to cent
    #cois will be used for count number of coins
    
    cents = int(round(dollors * 100))
    coins = int(0)
    
    #start greedy algorithm
    #quarter $0.25
    #FYI ptyhon will not support incremental increase operator like ++, you can use i += i instead of
    
    while cents >= 25:
        cents -= 25
        coins += 1 
        
    #dime $0.1
    while cents >= 10:
        cents -= 10
        coins += 1
    
    #nickel $0.5
    while cents >= 5:
        cents -= 5
        coins += 1
    
    #penny $0.01
    while cents >= 1:
        cents -= 1
        coins += 1
    
    #print number of coins
    print(coins)
if __name__ == "__main__":
    main()
