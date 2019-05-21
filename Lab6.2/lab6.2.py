import string
import operator
import itertools

def AND(invertidos):

    print("\n")
    word1 = input()
    word2 = input()
    temp1 = []
    temp2 = []
    resultado = []
    for x in invertidos:
        if word1 == x:
            temp1 = invertidos.get(x)
        if word2 == x:
            temp2 = invertidos.get(x)

    for x, y in zip(temp1, temp2):
        if x == y:
            print(x + ' ' + y)
            resultado.append(x)

    return resultado







SW = open("stopwords.txt", "r")
file1 = open("libros/libro1.txt", "r")
file2 = open("libros/libro2.txt", "r")
file3 = open("libros/libro3.txt", "r")
file4 = open("libros/libro4.txt", "r")
file5 = open("libros/libro5.txt", "r")
file6 = open("libros/libro6.txt", "r")
stopwords = []
palabras = []
contents1 = file1.read()
filtrado = contents1.translate(str.maketrans('', '', string.punctuation))
for x in SW:
    a = x.rstrip()
    stopwords.append(a)

librowords = filtrado.split()

resultado = [palabra for palabra in librowords if palabra.lower() not in stopwords]

for x in resultado:
    palabras.append(x)

contents2 = file2.read()
filtrado = contents2.translate(str.maketrans('', '', string.punctuation))
librowords = filtrado.split()
resultado = [palabra for palabra in librowords if palabra.lower() not in stopwords]

for x in resultado:
    palabras.append(x)

contents3 = file3.read()
filtrado = contents3.translate(str.maketrans('', '', string.punctuation))
librowords = filtrado.split()
resultado = [palabra for palabra in librowords if palabra.lower() not in stopwords]

for x in resultado:
    palabras.append(x)

contents4 = file4.read()
filtrado = contents4.translate(str.maketrans('', '', string.punctuation))
librowords = filtrado.split()
resultado = [palabra for palabra in librowords if palabra.lower() not in stopwords]

for x in resultado:
    palabras.append(x)

contents5 = file5.read()
filtrado = contents5.translate(str.maketrans('', '', string.punctuation))
librowords = filtrado.split()
resultado = [palabra for palabra in librowords if palabra.lower() not in stopwords]

for x in resultado:
    palabras.append(x)

contents6 = file6.read()
filtrado = contents6.translate(str.maketrans('', '', string.punctuation))
librowords = filtrado.split()
resultado = [palabra for palabra in librowords if palabra.lower() not in stopwords]

for x in resultado:
    palabras.append(x)

frequencia = {}
for x in palabras:
    frequencia[x] = 0
dictionary = {}

for A in palabras:
    dictionary[A] = [0,0,0,0,0,0]
    if contents1.find(A) != -1:
        temp = dictionary.get(A)
        temp[0]=1;
        dictionary[A]=temp;
    if contents2.find(A) != -1:
        temp = dictionary.get(A)
        temp[1]=1;
        dictionary[A]=temp;
    if contents3.find(A) != -1:
        temp = dictionary.get(A)
        temp[2]=1;
        dictionary[A]=temp;
    if contents4.find(A) != -1:
        temp = dictionary.get(A)
        temp[3]=1;
        dictionary[A]=temp;
    if contents5.find(A) != -1:
        temp = dictionary.get(A)
        temp[4]=1;
        dictionary[A]=temp;
    if contents6.find(A) != -1:
        temp = dictionary.get(A)
        temp[5]=1;
        dictionary[A]=temp;


for A in palabras:
    if contents1.find(A) != -1:
        frequencia[A] += 1
    elif contents2.find(A) != -1:
        frequencia[A] += 1
    elif contents3.find(A) != -1:
        frequencia[A] += 1
    elif contents4.find(A) != -1:
        frequencia[A] += 1
    elif contents5.find(A) != -1:
        frequencia[A] += 1
    elif contents6.find(A) != -1:
        frequencia[A] += 1

sorted = sorted(frequencia.items(), key=operator.itemgetter(1))
sorted.reverse()
keys50 = []
i=0
top50 = {}
for x in sorted:
    if(i<50):
        keys50.append(x[0])
        i = i+1
i=0
for x in keys50:
    if x == sorted[i][0]:
        top50[x]=sorted[i][1]
        i+=1
i=0

invertidos = {}
for x in top50:
    invertidos[x] = []
    if dictionary.get(x)[0] == 1:
        invertidos.get(x).append('1')
    if dictionary.get(x)[1] == 1:
        invertidos.get(x).append('2')
    if dictionary.get(x)[2] == 1:
        invertidos.get(x).append('3')
    if dictionary.get(x)[3] == 1:
        invertidos.get(x).append('4')
    if dictionary.get(x)[4] == 1:
        invertidos.get(x).append('5')
    if dictionary.get(x)[5] == 1:
        invertidos.get(x).append('6')

stringY = ""
for x in invertidos:
    for y in invertidos.get(x):
        stringY += y + ', '
    print(x + ' -> ' + stringY)
    stringY = ""

print(AND(invertidos))