def encrypt_cipher(message, rotation):
    encrypted = ''
    for char in message:
        encrypted += apply_rot(char, rotation)
    return encrypted

def decrypt_cipher(message, rotation):
    return encrypt_cipher(message, 26-rotation)

def apply_rot(char, rot):
    if not char.isalpha():
        return char

    # Bring to a common denominator base of 26
    # Subtract by 65 if uppercase, 97 if lowercase.
    base = ord('a') if char.islower() else ord('A')
    index = ord(char) - base
    new_index = (index + rot) % 26
    return chr(base + new_index)

def main():
    print('Welcome to Caesar Cipher, Write your message suffixed with 0 or 1 to encrypt or decrypt respectively.')
    while True:
        message = input('Enter your message: ')
        mode = message[-1]
        if mode == '1':
            print('Decrypted message: ', decrypt_cipher(message[:-1], 3))
        elif mode == '0':
            print('Encrypted message: ', encrypt_cipher(message[:-1], 3))
        else:
            print('Invalid mode, try again.')

if __name__ == '__main__':
    main()
