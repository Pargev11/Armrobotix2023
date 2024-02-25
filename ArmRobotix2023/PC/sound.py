from symbol import pass_stmt
import pygame
import threading
import time
pygame.init()

class audio:
    def __init__(self):
        self.fl = 0
        self.b = 0
        self.n = ""
        self.pat = "C:\\Users\\Lenovo\\Desktop\\obj"
    def findnumber(self,num,name):
        time.sleep(4)
        self.n = name
        if num%100 == 0: num = num +1
        if num%200 == 0: num = num +1
        self.fl = 0
        if num < 100:
            self.b = num
            self.fl = 1
        threading.Thread(target = self.second).start()
        if int(num/100) == 1:
            self.fl = 2
            num = num-100
            self.b = num
            self.first(100)
        if int(num/200) == 1:
            self.fl = 4
            num = num-200
            self.b = num
            self.first(200)
        
        

    def first(self,a):
        file = self.pat+"\\audio\\"+str(a)+".mp3"
        pygame.mixer.music.load(file)
        pygame.mixer.music.play()

        while pygame.mixer.music.get_busy():
            pygame.time.Clock().tick(10)
    def second(self):
        while self.fl == 0:
            # print(1)
            pass
        if self.fl == 2:
            time.sleep(0.6)
        elif self.fl == 4:
            time.sleep(1)
        file = self.pat+"\\audio\\"+ str(self.b) +".mp3"
        pygame.mixer.music.load(file)
        pygame.mixer.music.play()
        while pygame.mixer.music.get_busy():
            pygame.time.Clock().tick(10)
        print(1111111)
        self.tr()
    def tr(self):
        file = self.pat+"\\audio\\"+ str(self.n) +".mp3"
        pygame.mixer.music.load(file)
        pygame.mixer.music.play()
        while pygame.mixer.music.get_busy():
            pygame.time.Clock().tick(10)


