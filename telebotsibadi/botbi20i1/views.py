from django.shortcuts import render
from django.http import HttpResponse, JsonResponse
import json
# Create your views here.
from .models import Laboratory, Student, Hint, Stats, Group


def group(request, id):
    students = Student.objects.filter(group_id__id=id)


    stats = Stats.objects.all().order_by('lab')

    context = {

        'students': students,
        'stats': stats,
    }

    return render(request, template_name='bi-20i1.html', context=context)


def facePage(request):
    students = Student.objects.all()
    groups = Group.objects.all()

    stats = Stats.objects.all().order_by('lab')

    context = {
        'groups': groups,
        'students': students,
        'stats': stats,
    }

    return render(request, template_name='facePage.html', context=context)


def index(request):
    data = {}
    datas = {}
    m = 0
    students = Student.objects.filter(group_id__id=4)
    for student in students:

        data.update({str(student.personal_number): {'name': student.name, 'rating': student.rating, 'labs': {}}})
        i = 1
        m +=1
        labs = Stats.objects.filter(student=student).filter(status=False).prefetch_related('lab')
        for lab in labs:
            data[str(student.personal_number)]['labs'].update({
                i: {
                    'name': lab.lab.name,
                    'description': lab.lab.description,
                    'status': int(lab.status),
                    'hints': {}
                }
            })

            hints = Hint.objects.filter(lab=lab.lab.id)
            j = 1
            for hint in hints:
                data[str(student.personal_number)]['labs'][i]['hints'].update({j: hint.text})
                j += 1
            i += 1

    return JsonResponse(data)


def table_view(request):
    students_bi20i1 = Student.objects.filter(group_id__id=4)
    stats = Stats.objects.all().order_by('lab')
    context = {
        'students_bi20i1': students_bi20i1,
        'stats': stats,
    }

    return render(request, template_name="table.html", context=context)


def update_changes(request):
    if (request.GET):
        stats = Stats.objects.get(pk=request.GET['stats_id'])
        user = Student.objects.get(pk=stats.student.id)
        if request.GET['status'] == '1':
            stats.status = True

        else:
            stats.status = False
        labs_kt1 = user.labs.filter(kt=1)
        labs_kt2 = user.labs.filter(kt=2)
        labs_kt3 = user.labs.filter(kt=3)
        labs_done_kt1 = Stats.objects.filter(student=user, status=True, lab__kt=1)
        labs_done_kt2 = Stats.objects.filter(student=user, status=True, lab__kt=2)
        labs_done_kt3 = Stats.objects.filter(student=user, status=True, lab__kt=3)
        KT = stats.lab.kt

        sum_labs_1kt = len(labs_kt1)
        sum_labs_2kt = len(labs_kt2)
        sum_labs_3kt = len(labs_kt3)
        update_rating = 100/3
        print(labs_kt1)
        print(stats.lab.kt)

        try:
            lab_point_kt1 = 100 / sum_labs_1kt
            update_rating_point_1kt = update_rating / sum_labs_1kt
        except ZeroDivisionError:
            lab_point_kt1 = 0
            update_rating_point_1kt = 0
        try:
            lab_point_kt2 = 100 / sum_labs_2kt
            update_rating_point_2kt = update_rating / sum_labs_2kt
        except ZeroDivisionError:
            lab_point_kt2 = 0
            update_rating_point_2kt = 0
        try:
            lab_point_kt3 = 100 / sum_labs_3kt
            update_rating_point_3kt = update_rating / sum_labs_3kt
        except ZeroDivisionError:
            lab_point_kt3 = 0
            update_rating_point_3kt = 0


        if KT == 1:
            user.rating_1KT += lab_point_kt1*len(labs_done_kt1)
            user.rating += update_rating_point_1kt
        elif KT == 2:
            user.rating_2KT += lab_point_kt2*len(labs_done_kt2)
            user.rating += update_rating_point_2kt
        else:
            user.rating_3KT += lab_point_kt3*len(labs_done_kt3)
            user.rating += update_rating_point_3kt


        user.save()
        stats.save()

    return JsonResponse(
        {
            'status': stats.status,
            'user_id': user.id,
            'lab_id': request.GET['stats_id'],
            'kt_1': float('{:.2f}'.format(user.rating_1KT)),
            'kt_2': float('{:.2f}'.format(user.rating_2KT)),
            'kt_3': float('{:.2f}'.format(user.rating_3KT)),
            'rating': float('{:.2f}'.format(user.rating))
        })
