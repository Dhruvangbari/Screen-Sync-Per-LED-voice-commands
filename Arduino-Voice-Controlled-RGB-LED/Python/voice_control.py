import sounddevice as sd
import queue
import json
import serial
from vosk import Model, KaldiRecognizer

arduino = serial.Serial("COM3", 9600)
model = Model("vosk-model-small-en-us-0.15")

keywords = '''
["red","read","rad","lal","laal","green","grin","hara","harra",
"blue","blew","nila","neela","rainbow","party","dance","dj","pulse",
"beat","off","stop","band"]
'''
rec = KaldiRecognizer(model, 16000, keywords)

q = queue.Queue()

def callback(indata, frames, time, status):
    q.put(bytes(indata))

sd.RawInputStream(
    samplerate=16000,
    blocksize=8000,
    dtype="int16",
    channels=1,
    callback=callback
).start()

commands = {
    "red":"E1","read":"E1","rad":"E1","lal":"E1","laal":"E1",
    "green":"E2","grin":"E2","hara":"E2","harra":"E2",
    "blue":"E3","blew":"E3","nila":"E3","neela":"E3",
    "rainbow":"E4","pulse":"E5","beat":"E5",
    "party":"E6","dance":"E6","dj":"E6",
    "off":"E0","stop":"E0","band":"E0"
}

print("Speak command...")

while True:
    data = q.get()
    if rec.AcceptWaveform(data):
        text = json.loads(rec.Result()).get("text","").split()
        for word in text:
            if word in commands:
                arduino.write((commands[word] + "\n").encode())
                break
