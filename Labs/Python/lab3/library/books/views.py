from django.shortcuts import render
from books.models import Books, Author
from library.settings import BASE_DIR


# Create your views here.


def index(request):
    books = Books.objects.all()

    return render(request, 'books/index.html', {'books': books})


def book_details(request, book_id):
    book = Books.objects.get(id=book_id)
    authors = Books.objects.get(id=book_id).authors.all()
    context = {'book': book, 'authors': authors, 'BASE_DIR': BASE_DIR}
    return render(request, 'books/book_details.html', context)


def author_details(request, author_id):
    author = Author.objects.get(id=author_id)
    author_books = Author.objects.get(id=author_id).book_name.all()
    context = {"author": author, 'author_books': author_books}
    return render(request, 'books/author_details.html', context)
