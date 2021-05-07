import random, time, os, sys
random.seed(time.time())
with open("words.txt","r") as file:
    words = file.readlines()

WORD = random.choice(words).strip()

print(f"{WORD=}")
user_word = input("Enter Guess: ")

if user_word.find("os.system") != -1 or user_word.find(";") != -1:
    print("trying to trich me are you?")
    sys.exit(0)

user_word = eval(user_word)
print(f"you entered : {user_word}")

if user_word == WORD:
    os.system("/bin/sh")

else:
    print("epic fail")