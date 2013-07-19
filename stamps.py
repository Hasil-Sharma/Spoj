k = 1
def printing(nums):
    global k
    print "Scenario #" + str(k) + ":"
    print str(nums) + "\n"
    k += 1
import sys
input_data = sys.stdin.read()
input_data = input_data.split('\n')
input_data.remove('')
t = int(input_data[0])
index_t = 1
while index_t <= 2*t:
    cards_needed = input_data[index_t].split(' ')
    cards_needed = map(int, cards_needed)
    cards_needed = cards_needed[0]
    cards_offered = input_data[index_t + 1].split(' ')
    cards_offered = map(int, cards_offered)
    sum_of_cards = sum(cards_offered)
    if sum_of_cards < cards_needed:
        printing("impossible")
    else:
        cards_offered.sort()
        sums,i = 0,0
        while sums < cards_needed:
            sums += cards_offered.pop()
            i += 1
        printing(i)
    index_t += 2
        
