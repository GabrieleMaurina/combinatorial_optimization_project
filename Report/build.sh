#!/usr/bin/env bash

export TEXINPUTS=..//:
pdflatex --shell-escape Report &&
pdflatex --shell-escape Report &&
rm -rf Report.aux Report.log _minted-Report Report.toc
xdg-open Report.pdf
