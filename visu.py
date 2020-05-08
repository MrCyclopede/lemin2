#!/usr/local/bin/python3

from tkinter import *
import sys


class Parsing:
    def __init__(self):
        data = sys.stdin.readlines()
        self.links = []
        self.comments = []
        self.moves = []
        self.rooms = []
        self.start = []
        self.end = []
        self.ants = []
        for i, line in enumerate(data):
            if '#' in line:
                if line.startswith("##start"):
                   self.start = data[i + 1].split()
                elif line.startswith("##end"):
                    self.end = data[i + 1].split()
                else:
                    self.comments.append(line.strip('\n'))
            elif '-' in line and line[0] != 'L':
                self.links.append(line.strip('\n').split('-'))
            elif '-' in line:
                self.moves.append(line.strip('\n'))
            else:
                thing = line.strip('\n').split()
                if len(thing) == 3 and thing[1].isdigit() and thing[2].isdigit():
                    self.rooms.append(thing)
                elif len(thing) == 1:
                    self.ants = int(thing[0]);
  

class Room:
    def __init__(self,room_string):
        self.x = int(room_string[1])
        self.y = int(room_string[2])
        self.name = room_string[0]
    
class Rooms:
    def __init__(self, w, s, rooms_string):
        self.rooms_list = []
        self.canva = Canvas(w, width = s.x_w , height = s.y_w, bg="blue")
        for line in rooms_string:
            self.rooms_list.append(Room(line))

    def scale(self, s):
        x_mult = s.x_w * 0.9 / max(self.rooms_list[1])
        y_mult = s.y_w * 0.9 / max(self.rooms.list[2])
        for room in self.rooms_list:
            room.x *= multiplier
            room.y *= multiplier

#class Link:
#    def __init__(self, w, a, b):
#        self.a = a
#        self.b = b
#        self.image = Canvas(w, width = a.x - b.x, height = a.y - b.y)


def close(event):
    #w.withdraw() # if you want to bring it back
    sys.exit() # if you want to exit the entire thing


def keyup(e):
    print ('up', e.char)
def keydown(e):
    print ('down', e.char)




class Settings:
    def __init__(self, rooms):
        self.x_w = "1000"
        self.y_w = "1000"


def draw(canva, rooms_list):
    for room in rooms_list:
        canva.create_oval(room.x, room.y, room.x + 10, room.y + 10,
                fill="red")
    canva.pack()



if __name__ == '__main__':
    p = Parsing()
    s = Settings(p.rooms)



    w = Tk()
    w.geometry(s.x_w + "x" + s.y_w)

    r = Rooms(w, s, p.rooms)
    r.draw()



    w.bind('<Escape>', close)

w.mainloop()





