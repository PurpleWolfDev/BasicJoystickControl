import serial
from pynput.keyboard import Controller as KeyboardController, Key
from pynput.mouse import Controller as MouseController, Button

keyboard = KeyboardController()
mouse = MouseController()
ser = serial.Serial('COM6', 9600)  # Update COM port if needed

# Movement mapping: direction -> set of keys
direction_keys = {
    "FORWARD": {'w'},
    "BACKWARD": {'s'},
    "LEFT": {'w', 'a'},            # Diagonal strafe style
    "RIGHT": {'w', 'd'},
    "FORWARD LEFT": {'w', 'a'},
    "FORWARD RIGHT": {'w', 'd'},
    "BACKWARD LEFT": {'s', 'a'},
    "BACKWARD RIGHT": {'s', 'd'}
}

# Other key mappings
special_keys = {
    "SHIFT": Key.shift,
}

# Track currently pressed keys
pressed_keys = set()

def press_keys(keys):
    for key in keys:
        if key not in pressed_keys:
            keyboard.press(key)
            pressed_keys.add(key)

def release_keys(keys):
    for key in keys:
        if key in pressed_keys:
            keyboard.release(key)
            pressed_keys.remove(key)

def release_all_keys():
    release_keys(pressed_keys.copy())

while True:
    line = ser.readline().decode('utf-8').strip()
    print(f"Received: {line}")

    if line in direction_keys:
        release_all_keys()
        press_keys(direction_keys[line])

    elif line == "STOP":
        release_all_keys()

    elif line == "SHIFT":
        press_keys({Key.shift})

    elif line == "SHIFT_RELEASE":
        release_keys({Key.shift})

    elif line == "LEFTCLK":
        press_keys({'r'})

    elif line == "LEFTCLK_RELEASE":
        release_keys({'r'})

    elif line == "RIGHTCLK":
        mouse.click(Button.right, 1)
