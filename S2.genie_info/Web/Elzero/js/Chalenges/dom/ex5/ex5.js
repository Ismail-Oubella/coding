for (image of document.images) {
    if (image.hasAttribute("alt")) { image.setAttribute("alt", "Old") }
    else image.setAttribute("alt", "Elzero New")
}