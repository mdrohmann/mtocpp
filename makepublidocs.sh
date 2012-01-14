#!/bin/bash
rm -rf ~/aghwww/MoRePaS/software/mtocpp/docs/current
cmake -DCMAKE_INSTALL_PREFIX="~/agh" -DCUSTOM_DOC_DIR="~/aghwww/MoRePaS/software/mtocpp/docs/current" ..
make install