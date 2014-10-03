TARGET=analisisestabilidad
SOUDIR=./temas/
OUTDIR=./PDF's/
.PHONY: all handout move clean

all: handout move clean

handout:
	@echo "==============================================="
	@echo "Compilando con pdflatex, el archivo:" $(TARGET)
	@pdflatex -interaction=batchmode "$(SOUDIR)$(TARGET).tex"
	@pdflatex -interaction=batchmode "$(SOUDIR)$(TARGET).tex"
	@pdflatex -interaction=batchmode "$(SOUDIR)$(TARGET).tex"

move:
	@echo "==============================================="
	@echo "Moviendo el archivo a la carpeta de PDF's."
	@mv "$(TARGET).pdf" "$(OUTDIR)$(TARGET).pdf"

clean:
	@echo "==============================================="
	@echo "Quitando archivos irrelevantes."
	@rm -rf *.aux *.log *.fdb_latexmk *.synctex.gz *.out
