import unittest
import smsutil
from decoder import *


class testDecode(unittest.TestCase):
    def test(self):
        file = (
            'this is line 1 of the file'
            'this is line 2 of the file'
            'is this line 3? I don''t know'
            'this is line 4.'
        )
        decoded = decoder(file)
        encoded = decoded.encode('gsm7')
        self.assertEqual(decoded, encoded)