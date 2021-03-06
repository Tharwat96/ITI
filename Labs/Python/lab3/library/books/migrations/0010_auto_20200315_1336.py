# Generated by Django 2.1.5 on 2020-03-15 13:36

from django.db import migrations, models


class Migration(migrations.Migration):

    dependencies = [
        ('books', '0009_auto_20200314_2221'),
    ]

    operations = [
        migrations.AlterField(
            model_name='author',
            name='book_name',
            field=models.ManyToManyField(blank=True, related_name='books', to='books.Books', verbose_name='list of books'),
        ),
    ]
