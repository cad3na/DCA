TARGET=teoriadecontrol
OUTDIR=./PDF's/

all: pdf clean move

pdf:
	@echo "==============================================="
	@echo "Compilando con pdflatex, el archivo:" $(TARGET)
	@pdflatex -interaction=batchmode $(TARGET).tex
	@pdflatex -interaction=batchmode $(TARGET).tex

clean:
	@echo "==============================================="
	@echo "Quitando archivos irrelevantes."
	@rm -rf *.aux *.log *.fdb_latexmk  *.synctex.gz *.out

move:
	@echo "==============================================="
	@echo "Moviendo el archivo a la carpeta de PDF's."
	@mv "$(TARGET).pdf" "$(OUTDIR)$(TARGET).pdf"
