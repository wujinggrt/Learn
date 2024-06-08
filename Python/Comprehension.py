# list comprehensions
rows = range(3, 5)
cols = range(1, 5)
cells = [(r, c) for r in rows for c in cols]
print(cells) # [(3, 1), (3, 2), (3, 3), (3, 4), (4, 1), (4, 2), (4, 3), (4, 4)]
 
# dictionary comprehensions
word = 'letters'
letter_counts = {letter: word.count(letter) for letter in word}
print(letter_counts) # {'l': 1, 'e': 2, 't': 2, 'r': 1, 's': 1}

# set comprehensions
a_set = {number for number in range(1, 6) if number % 3 == 1}
print(a_set) # {1, 4}