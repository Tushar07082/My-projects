import random
print("Welcome to the perfect guess\nCheck how accurately you guesses")
print("Enter the range in which you want to play this game:")
a = input().split()
x = int(a[0])
y = int(a[1])
num = random.randint(x,y)
guess = int(input("Computer has choosen its number \nEnter you guess"))
i = 1
while guess != num :
        if(guess > num):
                guess = int(input("Shorter number please:"))
        else :
                guess = int(input("Larger number please:"))
        i += 1
print(f"Correct answer\nYou took {i} guesses to complete this game")
