from django.shortcuts import render
from user_profile.models import Profile
from user_profile.serializers import ProfileSerializer
from rest_framework import viewsets


class ProfileViewSet(viewsets.ModelViewSet):
    serializer_class = ProfileSerializer
    queryset = Profile.objects.all()
    serializer_actions = {
        'list': ProfileSerializer,
        'create': ProfileSerializer,
        'retrieve': ProfileSerializer,
        'update': ProfileSerializer,
        'partial_update': ProfileSerializer,
    }