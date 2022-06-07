'''
Construa uma função que retorne os horários disponíveis para duas pessoas poderem fazer uma reunião

Sample input:
[['9:00', '10:30'], ['12:00', '13:00'], ['16:00', '18:00']] # Horário em que a pessoa NÃO está disponível
['9:00', '20:00'] # Horário em que ela pode ter a(s) reunião(ões) ao longo do dia
[['10:00', '11:30'], ['12:30', '14:30'], ['14:30', '15:00'], ['16:00', '17:00']] # Horário em que a pessoa NÃO está disponível
['10:00', '18:30'] # Horário em que ela pode ter a(s) reunião(ões) ao longo do dia
30 # Tempo mínimo da reunião
Sample output: [['11:30', '12:00'], ['15:00', '16:00'], ['18:00', '18:30']]
'''

def stringToMinutes(string):
    h, m = map(int, string.split(':'))
    return m + (h * 60)

def minutesToString(minutes):
    h, m = divmod(minutes, 60)
    return f"{h}:{m:02}"

def toArray(meetings, boundaries):
    array = [ 1 for x in range(24*60) ]
    for un in meetings:
        start, finish = map(stringToMinutes, un)

        for i in range(start, finish + 1):
            array[i] = 0
    
    initialHour, finalHour = map(stringToMinutes, boundaries)

    for i in range(initialHour + 1):
        array[i] = 0
    
    for i in range(finalHour, len(array)):
        array[i] = 0

    return array

def available(a, ba, b, bb, t):
    la, lb = toArray(a, ba), toArray(b, bb)


    iniciou = False
    a = list()
    aux = 0
    for i in range(60*24):
        if la[i] and lb[i]:
            if not iniciou:
                aux = i - 1 
                iniciou = True
        else:
            if iniciou:
                iniciou = False
                if i - aux >= t:
                    a.append([minutesToString(aux), minutesToString(i)])
    return a


if __name__ == "__main__":
    a = available(
        [['9:00', '10:30'], ['12:00', '13:00'], ['16:00', '18:00']],
        ['9:00', '20:00'],
        [['10:00', '11:30'], ['12:30', '14:30'], ['14:30', '15:00'], ['16:00', '17:00']],
        ['10:00', '18:30'],
        30
    )
    print(a)