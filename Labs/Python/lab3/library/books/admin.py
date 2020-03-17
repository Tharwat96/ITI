from django.contrib import admin
from books.models import Books, Author

# Register your models here.
admin.site.register(Books)
admin.site.register(Author)
