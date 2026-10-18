from dataclasses import dataclass, replace

@dataclass(frozen=True)
class Point:
    x: int
    y: int

    def move(self, dx: int, dy: int):
        return replace(self, x=self.x+dx, y=self.y+dy)
        #replace creates a new obj

def append_items(items, item):
    return items + (item,)

def shallow_trap():
    holder = ([1, 2], "hello")
    holder[0].append(4)
    return holder


if __name__ == "__main__":
    #Total Objects created = 2
    print(Point(2,3).move(1,2)) #New Point obj was created, did not modify the original one
    print(append_items((1, 2), 3))
    print(shallow_trap())
