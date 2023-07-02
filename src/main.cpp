#include <QApplication>
#include <QWidget>
#include <QTextBrowser>
#include <tidy/tidy.h>
#include <tidy/tidybuffio.h>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // Read the HTML content from a file or a string
    const char* htmlContent = "<html><body><h1>Hello, World!</h1></body></html>";

    // Initialize Tidy
    TidyDoc tidyDoc = tidyCreate();
    TidyBuffer tidyBuffer;
    tidyBufInit(&tidyBuffer);

    // Parse the HTML content with Tidy
    tidyParseString(tidyDoc, htmlContent);

    // Clean up and repair the HTML
    tidyCleanAndRepair(tidyDoc);

    // Convert the parsed HTML tree to a plain text representation
    tidySaveBuffer(tidyDoc, &tidyBuffer);

    // Create a Qt widget for displaying the HTML content
    QWidget widget;
    QTextBrowser textBrowser(&widget);
    textBrowser.setHtml(tidyBuffer.bp);

    // Show the widget
    widget.show();

    // Enter the main event loop
    return app.exec();
}
