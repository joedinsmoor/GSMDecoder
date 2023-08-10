import unittest
import smsutil
from src.decoder import decoder


class testDecode(unittest.TestCase):
    def test(self):
        file = 'tests/file.dat'
        decoded = decoder(file)
        encoded = decoded.encode('gsm7')
        self.assertEqual(decoded, encoded)