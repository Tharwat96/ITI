# Generated by Django 2.1.5 on 2020-03-14 22:21

from django.db import migrations, models


class Migration(migrations.Migration):

    dependencies = [
        ('books', '0008_auto_20200314_2106'),
    ]

    operations = [
        migrations.AlterField(
            model_name='books',
            name='cover_pic',
            field=models.ImageField(default='books/400px600px-r01BookNotPictured.jpg', upload_to='books/'),
        ),
    ]
