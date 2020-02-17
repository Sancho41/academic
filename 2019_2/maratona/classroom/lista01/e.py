'''
    http://codeforces.com/contest/381/problem/A

    Sereja and Dima
    
    Sereja and Dima play a game. The rules of the game are very simple. The players have n cards in a row. Each card contains a number, all numbers on the cards are distinct. The players take turns, Sereja moves first. During his turn a player can take one card: either the leftmost card in a row, or the rightmost one. The game ends when there is no more cards. The player who has the maximum sum of numbers on his cards by the end of the game, wins.
    Sereja and Dima are being greedy. Each of them chooses the card with the larger number during his move.
    Inna is a friend of Sereja and Dima. She knows which strategy the guys are using, so she wants to determine the final score, given the initial state of the game. Help her.

    Input
    The first line contains integer n (1 ≤ n ≤ 1000) — the number of cards on the table. The second line contains space-separated numbers on the cards from left to right. The numbers on the cards are distinct integers from 1 to 1000.

    Output
    On a single line, print two integers. The first number is the number of Sereja's points at the end of the game, the second number is the number of Dima's points at the end of the game.

    Examples
        input:
            4
            4 1 2 10
        output:
            12 5
            
        input:
            7
            1 2 3 4 5 6 7
        output:
            16 12
    Note
    In the first sample Sereja will take cards with numbers 10 and 2, so Sereja's sum is 12. Dima will take cards with numbers 4 and 1, so Dima's sum is 5.
'''

qnt, c = int(input()), list(map(int, input().split()))
left,  right = 0, qnt - 1
sereja, dima, serejaTurn = 0, 0, True

while left <= right:
    valor = c[left] if c[left] > c[right] else c[right]
    if c[left] > c[right]: left += 1
    else: right -= 1

    sereja += valor if serejaTurn else 0
    dima += valor if not serejaTurn else 0
    serejaTurn = not serejaTurn

print(sereja, dima)    