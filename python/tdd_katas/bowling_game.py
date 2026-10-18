def score_game():
    rolls = []
    for frame in range(10):
        roll1 = int(input(f"Frame {frame + 1}, Roll 1: "))
        roll2 = int(input(f"Frame {frame + 1}, Roll 2: "))
        rolls.append((roll1, roll2))
    
    score = 0

    score = 10 + rolls[1] + rolls[2]
    print(score)