import unittest
import smsutil
from src.decoder import *


class testDecode(unittest.TestCase):
    def test(self):
        file = 'tests/file.dat'
        decoded = with_regex(file)
        encoded = decoded.encode('gsm7')
        self.assertEqual(decoded, encoded)