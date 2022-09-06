import random
words = ['remorsee', 'mercifule', 'mysteeriousee', 'adveantagee']

word = random.choice(words)
hangman = """
  +---+
  |   |
      |
      |
      |
      |
=========
"""
guess = input('Please guess the word with either a letter or the full word.')
positions = 0
def display_board():
    print(hangman)
#def get_pos():
    
def if_is(letter: str):
    if letter in word:
        return True
    else:
        return False
if guess in word:
    pos = []
    while positions < len(word):
        positions = word.find(guess, positions)
        if positions == -1:
            break
        print('Your guess has been found at index:', positions)
        pos.append(positions)
        positions += 1 # +2 because len('ll') == 2
        
    print(pos[0:])
    print(word)

    print('Correct')
