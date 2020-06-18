RUBBER=rubber
SCREEN=screen
VIEWER=xdg-open

all: main.pdf

show: main.pdf
	$(SCREEN) -dm $(VIEWER) main.pdf

main.pdf: main.tex
	$(RUBBER) -d main.tex

%.eps: %.svg
	inkscape $< -E $@ --export-ignore-filters --export-ps-level=3

clean: clean-temp
	rm -f *.pdf
	rm -f *.zip
	rm -f *.npy

clean-temp:
	$(RUBBER) --clean main.tex
	rm -f *.eps
	rm -f *-eps-converted-to.pdf
