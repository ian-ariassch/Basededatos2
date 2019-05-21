import json
import nltk
nltk.download('punkt')
import re
from nltk.tokenize import word_tokenize, sent_tokenize
import math

def frequencia(string, palabra):
    x = string.split()
    return x.count(palabra)

def contar(x):
    return len(x.split())

def borrarduplicados(x):
  return list(dict.fromkeys(x))

def removeSpecialChars(s):
    st = re.sub('[^\w\s]', '', s)
    st = re.sub('_', '', st)

    st = re.sub('\s+', ' ', st)
    st = st.strip()

    return st
def tf(docInfo, frequenciadict):
    tfScores = []
    for temp in frequenciadict:
        id = temp['docId']
        for j in temp['freqDictionary']:
            t = {'docId:': id, 'tfScore:': temp['freqDictionary'][j] / docInfo[id - 1]['docLength'], 'key:': j}
            tfScores.append(t)
    return tfScores


def idf(docInfo, freqDictionaryList):
    idfScores = []
    counter = 0
    for dict in freqDictionaryList:
        counter += 1
        for j in dict['freqDictionary'].keys():
            cnt = sum([j in temp['freqDictionary'] for temp in freqDictionaryList])
            t = {'docId:': counter, 'idfScore:': math.log(len(docInfo) / cnt), 'key:': j}
            idfScores.append(t)
    return idfScores


def tfidf(tfScores, idfScores):
    tfidfScores = []
    for i in idfScores:
        for j in tfScores:
            if i['key'] == j['key'] and i['docId'] == j['docId']:
                t = {'docId:': i['docId'], 'tfidfScore:': i['idfScore'] * j['tfScore'], 'key:': j['key']}
        tfidfScores.append(t)
    return tfidfScores

idtweets = {}
palabracontador = {}
matriz = {}
palabrasfiltradas = []
stopwords = []
with open('tweets.json') as f:
    tweets = json.load(f)

for x in tweets:
    textito = removeSpecialChars(x["text"])
    idtweets[x["id"]]= textito

for x in idtweets:
    for y in idtweets.get(x).split():
        if y.lower() not in stopwords:
            matriz[y] = []

for x in idtweets:
    for y in idtweets.get(x).split():
        if y.lower() not in stopwords:
            temp = {}
            temp[x] = frequencia(idtweets.get(x),y)
            matriz.get(y).append(temp)
SW = open("stopwords.txt", "r")

for x in SW:
    a = x.rstrip()
    stopwords.append(a)


for x in matriz:
    print(x)
    print(matriz.get(x))
    print((len(matriz.get(x))))


