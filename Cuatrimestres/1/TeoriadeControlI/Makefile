TARGET=teoriadecontrol
OUTDIR=./PDF's/

complete: completebook completeebook

completebook: book movebook clean

completeebook: ebook moveebook clean

book: clean
	@echo "==============================================="
	@echo "Compilando con pdflatex, el archivo:" $(TARGET)
	@pdflatex -interaction=batchmode "\newif\ifebook\ebookfalse\input{$(TARGET).tex}"
	@pdflatex -interaction=batchmode "\newif\ifebook\ebookfalse\input{$(TARGET).tex}"
	@pdflatex -interaction=batchmode "\newif\ifebook\ebookfalse\input{$(TARGET).tex}"

ebook: clean
	@echo "==============================================="
	@echo "Compilando con pdflatex, el archivo:" $(TARGET)
	@pdflatex -interaction=batchmode "\newif\ifebook\ebooktrue\input{$(TARGET).tex}"
	@pdflatex -interaction=batchmode "\newif\ifebook\ebooktrue\input{$(TARGET).tex}"
	@pdflatex -interaction=batchmode "\newif\ifebook\ebooktrue\input{$(TARGET).tex}"

movebook:
	@echo "==============================================="
	@echo "Moviendo el archivo a la carpeta de PDF's."
	@mv "$(TARGET).pdf" "$(OUTDIR)$(TARGET).pdf"

moveebook:
	@echo "==============================================="
	@echo "Moviendo el archivo a la carpeta de PDF's."
	@mv "$(TARGET).pdf" "$(OUTDIR)$(TARGET)-ebook.pdf"

clean:
	@echo "==============================================="
	@echo "Quitando archivos irrelevantes."
	@rm -rf *.aux *.log *.fdb_latexmk  *.synctex.gz *.out
