
import random

def gamble(win_chance, amt):
    return random.random() < win_chance

n = 100
max_flips = 6
start_amt = 5
total_money_lost = 0
total_money_won = 0
max_flip_amt = 0
times_lost = 0
max_amount_of_flips = 0
win_chance = 0.4

for round in range(n):
    money_lost_in_round = 0
    round_won = False
    for i in range(max_flips):
        flip_amt = start_amt*(3**i)
        if(gamble(win_chance, flip_amt)):
            print(f"Won this round: {flip_amt - money_lost_in_round} at flip {i} with a bet of {flip_amt}")
            round_won = True
            total_money_won += (flip_amt - money_lost_in_round)
            max_flip_amt = max(max_flip_amt, flip_amt)
            max_amount_of_flips = max(max_amount_of_flips, i+1)
            break
        money_lost_in_round += flip_amt
    if(not round_won):
        print(f"Lost round, Money lost: {money_lost_in_round} gggggggggggggggggggggggggggggggggggggggggggggggggggggggg")
        total_money_lost += money_lost_in_round
        times_lost += 1

print(f"Total money won : {total_money_won}")
print(f"Total money lost: {total_money_lost}")
print(f"Total Profit: {total_money_won - total_money_lost}")
print(f"max flip amt: {max_flip_amt}")
print(f"max amount of flips: {max_amount_of_flips}")
print(f"Times Lost: {times_lost}, loss percentage: {times_lost/n}")

