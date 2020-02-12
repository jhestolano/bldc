import sys
import numpy as np
import matplotlib.pyplot as plt

def SerialPlotUnpack(fname):
  with open(fname) as file:
    rawdata = file.read()
  if len(rawdata) == 0:
    raise Exception('File does not contain data!')
  ''' Throw away frist line: it contains channel name '''
  rawdata = rawdata.splitlines()[1:]
  rawdata = map(lambda s: s.split(','), rawdata)
  return np.array(rawdata).astype('float')

if __name__ == '__main__':
  fname = sys.argv[1]
  print('{}'.format(SerialPlotUnpack(fname)))
