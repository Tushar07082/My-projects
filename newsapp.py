
import pyttsx3
import speech_recognition as sr
import datetime


def speak(audio):
        engine.say(audio)
        engine.runAndWait()



def wishMe():
        hour = int(datetime.datetime.now().hour)
        
        if(hour<12):
                speak("Good Morning,Sir")
        
        elif(hour<17):
                speak("Good Afternoon,Sir")
        
        else:
                speak("Good evening,RAKHI")
        
        speak("I am Jarvis, please tell me how may I help you")

engine = pyttsx3.init('sapi5')
voices = engine.getProperty('voices')
engine.setProperty('voice',voices[1].id)


if __name__=="__main__":
        # speak("I love you Tushar")
        # wishMe()
        while(1):
                speak("Jiji")
