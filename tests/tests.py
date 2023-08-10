import unittest
import smsutil
from . import decode_me


class testDecode(unittest.TestCase):
    def test(self):
        file = (
            'this is line 1 of the file'
            'this is line 2 of the file'
            'is this line 3? I don''t know'
            'this is line 4.'
        )
        decoded = decode_me(file)
        encoded = decoded.encode('gsm7')
        self.assertEqual(decoded, encoded)